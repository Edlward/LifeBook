from __future__ import print_function
from __future__ import unicode_literals

from builtins import str
from pathlib import Path
import json
import re


class Generator:
    def __init__(self):
        self._messages = None
        self._type_matcher = re.compile(r"^((?:u|s)?int(\d+)_t)(?:\[(\d+)\])?$")

    def load(self, file_name):
        with open(file_name) as json_data:
            self._messages = json.load(json_data)
        print("Loaded {} messages".format(len(self._messages)))

    @staticmethod
    def _camel_case_split(text):
        last_hit = 0
        result = []
        for i in range(len(text)):
            if text[i].isupper():
                result.append(text[last_hit:i].upper())
                last_hit = i
        result.append(text[last_hit:].upper())
        return result

    @staticmethod
    def _create_name(message_name, parameter_name, item_name):
        name_parts = message_name.split("_")
        if name_parts[-1] != parameter_name.upper():
            name_parts = name_parts + Generator._camel_case_split(parameter_name)
        name_parts.append(item_name.upper())
        # TODO: Make the name adhere to the 31-characters max length for identifiers.
        return "_".join(name_parts)

    def _output_file_header(self, out_file, file_name, description):
        out_file.write("/**\n")
        out_file.write("  \\file {}\n".format(Path(file_name).name))
        out_file.write("\n")
        out_file.write("  \\par Copyright &copy; 2019 ASSA ABLOY ES Production AB\n")
        out_file.write("  The copyright to this program is the property of ASSA ABLOY Entrance Systems AB\n")
        out_file.write("\n")
        out_file.write("  \\brief  {}\n".format(description))
        out_file.write("  \\author Daniel Hellsson\n")
        out_file.write("\n  This file is generated from messages.json and should not be edited directly\n")
        out_file.write("**/\n")
        out_file.write("\n")

    def _size_of_parameter(self, parameter_type):
        if not (isinstance(parameter_type, list) or isinstance(parameter_type, str)):
            raise ValueError("Size of parameter requires a type which is either a list or a string.")
        if isinstance(parameter_type, str):
            matches = self._type_matcher.match(parameter_type)
            if matches:
                parameter_size = int(matches.group(2))
                if parameter_size not in (8, 16, 32):
                    raise ValueError(
                        "Unknown parameter size {}".format(parameter_size))
                if matches.group(3):
                    # This means that it is an array.
                    parameter_size = parameter_size * int(matches.group(3))
                return parameter_size // 8
            elif parameter_type == "bool":
                return 1
            else:
                raise ValueError(
                    "Unknown parameter definition {}".format(parameter_type))
        else:
            # Enum, let's assume it fits in one byte. TODO: Don't assume that!
            return 1

    def _size_of_message(self, message_def):
        size = 0
        for parameter_name, parameter_def in message_def.items():
            size = size + self._size_of_parameter(parameter_def["type"])
        return size

    @staticmethod
    def _to_camel_case(text):
        words = text.split("_")
        return "".join([words[0]] + [x.title() for x in words[1:]])

    @staticmethod
    def _to_pascal_case(text):
        return "".join([x.title() for x in text.split("_")])

    def _get_transmit_function(self, message_name, message_def):
        parameters = ""
        for parameter_name, parameter_def in message_def.items():
            name = Generator._to_camel_case(parameter_name)
            if len(parameters) > 0:
                parameters = parameters + ", "
            parameters = parameters + "const "
            if isinstance(parameter_def["type"], str):
                if parameter_def["type"] == "bool":
                    parameters = parameters + "bool " + name
                else:
                    match = self._type_matcher.match(parameter_def["type"])
                    if match:
                        parameters = parameters + match.group(1) + " " + name
                        if match.group(3):
                            parameters = parameters + "[" + str(match.group(3)) + "]"
                    else:
                        raise ValueError("Parameter {} is of illegal type {}", parameter_name, parameter_def["type"])
            else:
                parameters = parameters + "uint8_t " + name
        return (Generator._to_pascal_case(message_name), parameters)

    def _as_prefixed_name(self, parameter_name, parameter_def):
        return self._as_hungarian_prefix(parameter_def["type"]) + parameter_name[0].upper() + parameter_name[1:]

    def _as_cpp_parameter_def(self, parameter_name, parameter_def, member=False):
        name = self._as_prefixed_name(parameter_name, parameter_def)
        if member:
            name = "m_" + name
        if isinstance(parameter_def["type"], str):
            match = self._type_matcher.match(parameter_def["type"])
            if match:
                if match.group(3):
                    return "{} {}[{}]".format(match.group(1), name, match.group(3))
                return "{} {}".format(match.group(1), name)
            if parameter_def["type"] == "bool":
                return "bool {}".format(name)
            raise ValueError("Unknown type for {}: {}".format(name, parameter_def["type"]))
        else:
            return "uint8_t {}".format(name)

    def _as_hungarian_prefix(self, parameter_type):
        if isinstance(parameter_type, str):
            match = self._type_matcher.match(parameter_type)
            if match:
                if match.group(3):
                    return "a"
                if match.group(1)[0] in ('u', 's'):
                    return match.group(1)[0:2] + match.group(2)
                return "s" + match.group(1)[0] + match.group(2)
            if parameter_type == "bool":
                return "b"
            raise ValueError("Unknown type for {}: {}".format(parameter_name, parameter_def["type"]))
        else:
            return "ui8"

    def output_message_ids(self, file_name):
        with open(file_name, "w") as message_ids_h:
            self._output_file_header(message_ids_h, file_name, "Defines the messages available in the product.")
            message_ids_h.write("#ifndef MESSAGE_IDS_HEADER_INCLUDE_GUARD\n")
            message_ids_h.write("#define MESSAGE_IDS_HEADER_INCLUDE_GUARD\n")
            message_ids_h.write("\n")
            message_ids_h.write("#include <stdint.h>\n")
            message_ids_h.write("\n")
            message_ids_h.write("//lint -e551 // Spurious error\n")
            message_ids_h.write("\n")
            message_ids_h.write("namespace messages\n")
            message_ids_h.write("{\n")
            msg_id = 0
            for message_name, message_def in self._messages.items():
                message_ids_h.write("    constexpr uint8_t {} = {}U;\n".format(message_name, msg_id))
                msg_id = msg_id + 1
            message_ids_h.write("\n")
            message_ids_h.write("    constexpr uint8_t NUMBER_OF_MESSAGE_IDS = {}U;\n".format(msg_id))
            for message_name, message_def in self._messages.items():
                for parameter_name, parameter_def in message_def.items():
                    if "type" not in parameter_def:
                        raise ValueError("'type' element in {}, parameter \"{}\" is missing.".format(message_name,
                                                                                                     parameter_name))
                    if not isinstance(parameter_def["type"], str):
                        message_ids_h.write("\n    // Parameters for {}\n".format(message_name))
                        enum_value = 0
                        for enum_name in parameter_def["type"]:
                            message_ids_h.write("    constexpr uint8_t {} = {}U;\n".format(
                                Generator._create_name(message_name,
                                                       parameter_name,
                                                       enum_name),
                                enum_value))
                            enum_value = enum_value + 1
            message_ids_h.write("\n    extern const uint8_t arMessageSize[NUMBER_OF_MESSAGE_IDS];\n")
            message_ids_h.write("}\n")
            message_ids_h.write("\n")
            message_ids_h.write("#endif // MESSAGE_IDS_HEADER_INCLUDE_GUARD\n")

    def output_messages_cpp(self, file_name):
        with open(file_name, "w") as messages_cpp:
            self._output_file_header(messages_cpp, file_name, "Implements message-related structures.")
            messages_cpp.write("#include <stdint.h>\n")
            messages_cpp.write("\n")
            messages_cpp.write("#include \"messageIds.h\"\n")
            messages_cpp.write("#include \"array_index.h\"\n")
            messages_cpp.write("namespace messages\n")
            messages_cpp.write("{\n")
            messages_cpp.write("    const uint8_t arMessageSize[NUMBER_OF_MESSAGE_IDS] = {\n")
            for message_name, message_def in self._messages.items():
                messages_cpp.write("        AI({}, {}U),\n".format(message_name, self._size_of_message(message_def)))
            messages_cpp.write("    };\n")
            messages_cpp.write("\n")
            messages_cpp.write("}\n")

    def _get_header_name(self, message_name):
        return "message_{}.hpp".format(message_name.lower())

    def _getter_name(self, function_name, parameter_def, function_prefix=""):
        prefix = self._as_hungarian_prefix(parameter_def["type"])
        if isinstance(parameter_def["type"], str):
            match = self._type_matcher.match(parameter_def["type"])
            if match:
                returns = match.group(1)
                if match.group(3):
                    returns = "const {}*".format(returns)
                    prefix = "p"
            elif parameter_def["type"] == "bool":
                returns = "bool"
            else:
                raise ValueError("Unknown type {} for function {}".format(parameter_def["type"], function_name))
        else:
            returns = "uint8_t"
        return "{} {}{}Get{}() const".format(returns, function_prefix, prefix, function_name)

    def output_message_headers(self, path):
        for message_name, message_def in self._messages.items():
            file_name = self._get_header_name(message_name)
            with Path(path, file_name).open("w") as header:
                self._output_file_header(header, file_name, "Header file for the message {}".format(message_name))
                header.write("#ifndef MESSAGE_{}_INCLUDE_GUARD\n".format(message_name))
                header.write("#define MESSAGE_{}_INCLUDE_GUARD\n\n".format(message_name))
                transmit_name, transmit_parameters = self._get_transmit_function(message_name, message_def)
                class_name = "Message{}".format(transmit_name)
                header.write("#include \"message.hpp\"\n\n")
                header.write("namespace messages {\n\n")
                header.write("    class {}: public messagesInternal::Message\n".format(class_name))
                header.write("    {\n")
                header.write("        private:\n")
                header.write("            {}() = delete;\n".format(class_name, class_name))
                header.write("            {}(const {}& source) = delete;\n".format(class_name, class_name))
                header.write("            {}& operator=(const {}& source) = delete;\n\n".format(class_name, class_name))
                header.write("        public:\n")
                header.write("            explicit {}(messages::MessageRouter& messageRouter);\n".format(class_name))
                header.write("            virtual ~{}();\n\n".format(class_name))
                header.write("            virtual bool bReceive() final;\n")
                header.write("            virtual void vSend() final;\n")
                for parameter_name, parameter_def in message_def.items():
                    function_name = "".join([x.title() for x in self._camel_case_split(parameter_name)])
                    definition = self._as_cpp_parameter_def(parameter_name, parameter_def)
                    header.write("            void vSet{}(const {});\n".format(function_name, definition))
                    header.write("            {};\n\n".format(self._getter_name(function_name, parameter_def)))
                if message_def:
                    header.write("        private:\n")
                    for parameter_name, parameter_def in message_def.items():
                        definition = self._as_cpp_parameter_def(parameter_name, parameter_def, True)
                        header.write("            {};\n".format(definition))
                header.write("    };\n\n")
                header.write("}\n")
                header.write("#endif // MESSAGE_{}_INCLUDE_GUARD\n".format(message_name))

    def _output_init_members(self, output, message_def):
        for parameter_name, parameter_def in message_def.items():
            prefix_name = self._as_prefixed_name(parameter_name, parameter_def)
            name = "m_" + prefix_name
            init_value = '0'
            if prefix_name[0] == 'b':
                init_value = 'false'
            elif prefix_name[0] == 'a':
                init_value = ''
            output.write("    , {}({})\n".format(name, init_value))

    def _output_message_imp_constructor(self, message_imp, message_name, message_def):
        transmit_name, transmit_parameters = self._get_transmit_function(message_name, message_def)
        class_name = "Message{}".format(transmit_name)
        message_imp.write("{0}::{0}(MessageRouter& messageRouter)\n".format(class_name))
        message_imp.write("    : Message(messageRouter, {})\n".format(message_name))
        if message_def:
            self._output_init_members(message_imp, message_def)
        message_imp.write("{\n}\n\n")
        message_imp.write("{0}::~{0}() {{ }}\n\n".format(class_name))

    def _get_length_of_array(self, parameter_def):
        match = self._type_matcher.match(parameter_def["type"])
        return match.group(3)

    def _output_message_imp_set_getters(self, message_imp, class_name, message_name, message_def):
        for parameter_name, parameter_def in message_def.items():
            function_name = "".join([x.title() for x in self._camel_case_split(parameter_name)])
            definition = self._as_cpp_parameter_def(parameter_name, parameter_def)
            name = self._as_prefixed_name(parameter_name, parameter_def)
            message_imp.write("void {}::vSet{}(const {})\n{{\n".format(class_name, function_name, definition))
            if name[0] == 'a':
                message_imp.write("    std::memcpy(m_{0}, {0}, {1});\n}}\n".format(name, self._get_length_of_array(parameter_def)))
            else:
                message_imp.write("    m_{0} = {0};\n}}\n\n".format(name))
            message_imp.write("{}\n{{\n".format(self._getter_name(function_name, parameter_def, class_name + "::")))
            message_imp.write("    return m_{};\n}}\n\n".format(name))

    def _output_message_imp_receive(self, message_imp, class_name, message_name, message_def):
        message_imp.write("bool {0}::bReceive()\n".format(class_name))
        if message_def:
            message_imp.write("{\n    int32_t si32Offset = 0;\n")
            message_imp.write("    const bool bSuccess = Message::bReceive();\n")
            message_imp.write("    if (bSuccess)\n")
            message_imp.write("    {\n")
            message_imp.write("        const uint8_t* const pMessageBuffer = getRouter().pGetMessagePayload();\n")
            for parameter_name, parameter_def in message_def.items():
                name = "m_" + self._as_prefixed_name(parameter_name, parameter_def)
                helper_function = self._as_hungarian_prefix(parameter_def["type"]) + "GetValue"
                if helper_function[0] == 'a':
                    match = self._type_matcher.match(parameter_def["type"])
                    helper_function = self._as_hungarian_prefix(match.group(1)) + "GetValue"
                    message_imp.write("        for (int32_t i = 0; i < {}; i++)\n        {{\n".format(match.group(3)))
                    message_imp.write("            {}[i] = messagesInternal::MessageHelper::{}(pMessageBuffer, si32Offset);\n".format(name, helper_function))
                    message_imp.write("        }\n")
                else:
                    message_imp.write("        {} = messagesInternal::MessageHelper::{}(pMessageBuffer, si32Offset);\n".format(name, helper_function))
            message_imp.write("    }\n")
            message_imp.write("    return bSuccess;\n}\n\n")
        else:
            message_imp.write("{\n    return Message::bReceive();\n}\n\n")

    def _output_message_imp_send(self, message_imp, class_name, message_name, message_def):
        message_imp.write("void {}::vSend()\n".format(class_name))
        message_imp.write("{\n")
        if message_def:
            message_imp.write("    const uint8_t cui8MessageId = ui8GetMessageId();\n")
            message_imp.write("    uint8_t* const pMessageBuffer = getRouter().pGetPayloadBuffer(cui8MessageId);\n")
            message_imp.write("    int32_t si32Offset = 0;\n")
            number_of_items = len(message_def.items())
            item_number = 0
            for parameter_name, parameter_def in message_def.items():
                prefixed_name = self._as_prefixed_name(parameter_name, parameter_def)
                name = "m_" + prefixed_name
                if prefixed_name[0] == 'a':
                    message_imp.write("    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, {0}, sizeof({0}), si32Offset);\n".format(name))
                else:
                    message_imp.write("    messagesInternal::MessageHelper::vSetValue(pMessageBuffer, {}, si32Offset);\n".format(name))
                item_number = item_number + 1
        message_imp.write("    getRouter().vTransmit();\n")
        message_imp.write("}\n\n")

    def output_message_implementation(self, file_name):
        with open(file_name, "w") as message_imp:
            self._output_file_header(message_imp, file_name, "Implementation of classes for messages.")
            message_imp.write("#include <cstring>\n")
            message_imp.write("#include \"messageIds.h\"\n")
            message_imp.write("#include \"messageRouter.hpp\"\n")
            message_imp.write("#include \"messageRouterBackend.hpp\"\n")
            message_imp.write("#include \"message.hpp\"\n")
            message_imp.write("#include \"message_helper.hpp\"\n")
            for message_name in self._messages.keys():
                header_name = self._get_header_name(message_name)
                message_imp.write("#include \"{}\"\n".format(header_name))
            message_imp.write("\n//lint -esym(438, offset) // We want to ignore dangling assignments of offset in auto-generated code\n")
            message_imp.write("\nnamespace messages {\n\n")
            for message_name, message_def in self._messages.items():
                self._output_message_imp_constructor(message_imp, message_name, message_def)
                class_name = "Message{}".format(self._to_pascal_case(message_name))
                self._output_message_imp_set_getters(message_imp, class_name, message_name, message_def)
                self._output_message_imp_receive(message_imp, class_name, message_name, message_def)
                self._output_message_imp_send(message_imp, class_name, message_name, message_def)
            message_imp.write("\n}\n")


if __name__ == "__main__":
    generator = Generator()
    #generator.load("components/messages/messages.json")
    generator.load("messages.json")
    generator.output_message_ids("../components/messages/sw200/inc/messageIds.h")
    generator.output_messages_cpp("../components/messages/sw200/src/messages.cpp")
    generator.output_message_headers("../components/messages/sw200/inc/messages/")
    generator.output_message_implementation("../components/messages/sw200/src/message.cpp")
