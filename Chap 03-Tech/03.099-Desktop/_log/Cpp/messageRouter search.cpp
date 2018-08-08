//by ENCODER_INFO.
		case messages::ENCODER_INFO:
			pui8MessagePayload = messageRouter->pGetMessagePayload();

pui8EncoderInfo = pMessageRouter->pGetPayloadBuffer(static_cast<uint8_t>(messages::ENCODER_INFO));

