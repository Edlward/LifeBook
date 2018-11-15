
#ifndef D_MockSupport_h
#define D_MockSupport_h

#include "MockCheckedActualCall.h"
#include "MockCheckedExpectedCall.h"
#include "MockExpectedCallsList.h"
#include "MockFailure.h"

class UtestShell;
class MockSupport;

/* This allows access to "the global" mocking support for easier testing */
MockSupport& mock(const SimpleString& mockName = "", MockFailureReporter* failureReporterForThisCall = NULL);

class MockSupport
{
public:
    MockSupport(const SimpleString& mockName = "");
    virtual ~MockSupport();

    virtual void strictOrder();
    virtual MockExpectedCall& expectOneCall(const SimpleString& functionName);
    virtual void expectNoCall(const SimpleString& functionName);
    virtual MockExpectedCall& expectNCalls(int amount, const SimpleString& functionName);
    virtual MockActualCall& actualCall(const SimpleString& functionName);
    virtual bool hasReturnValue();
    virtual MockNamedValue returnValue();
    virtual bool boolReturnValue();
    virtual bool returnBoolValueOrDefault(bool defaultValue);
    virtual int  intReturnValue();
    virtual int  returnIntValueOrDefault(int defaultValue);
    virtual unsigned int 		unsignedIntReturnValue();
    virtual long int 			longIntReturnValue();
    virtual long int 			returnLongIntValueOrDefault(long int defaultValue);
    virtual unsigned long int 	unsignedLongIntReturnValue();
    virtual unsigned long int 	returnUnsignedLongIntValueOrDefault(unsigned long int defaultValue);
    virtual unsigned int 		returnUnsignedIntValueOrDefault(unsigned int defaultValue);
    virtual const char* 		stringReturnValue();
    virtual const char* 		returnStringValueOrDefault(const char * defaultValue);
    virtual double 	returnDoubleValueOrDefault(double defaultValue);
    virtual double 	doubleReturnValue();
    virtual void* 	pointerReturnValue();
    virtual void* 	returnPointerValueOrDefault(void * defaultValue);
    virtual const void* returnConstPointerValueOrDefault(const void * defaultValue);
    virtual const void* constPointerReturnValue();
    virtual void (*returnFunctionPointerValueOrDefault(void (*defaultValue)()))();
    virtual void (*functionPointerReturnValue())();

    bool hasData(const SimpleString& name);
    void setData(const SimpleString& name, bool value);
    void setData(const SimpleString& name, int value);
    void setData(const SimpleString& name, unsigned int value);
    void setData(const SimpleString& name, const char* value);
    void setData(const SimpleString& name, double value);
    void setData(const SimpleString& name, void* value);
    void setData(const SimpleString& name, const void* value);
    void setData(const SimpleString& name, void (*value)());
    void setDataObject(const SimpleString& name, const SimpleString& type, void* value);
    MockNamedValue getData(const SimpleString& name);

    MockSupport* getMockSupportScope(const SimpleString& name);

    const char* getTraceOutput();
    /*
     * The following functions are recursively through the lower MockSupports scopes
     * This means, if you do mock().disable() it will disable *all* mocking scopes, including mock("myScope").
  	 */

    virtual void disable();
    virtual void enable();
    virtual void tracing(bool enabled);
    virtual void ignoreOtherCalls();

    virtual void checkExpectations();
    virtual bool expectedCallsLeft();

    virtual void clear();
    virtual void crashOnFailure(bool shouldFail = true);

    /*
     * Each mock() call will set the activeReporter to standard, unless a special reporter is passed for this call.
     */

    virtual void setMockFailureStandardReporter (MockFailureReporter* reporter);
    virtual void setActiveReporter				(MockFailureReporter* activeReporter);
    virtual void setDefaultComparatorsAndCopiersRepository();

    virtual void installComparator				(const SimpleString& typeName, MockNamedValueComparator& comparator);
    virtual void installCopier					(const SimpleString& typeName, MockNamedValueCopier& copier);
    virtual void installComparatorsAndCopiers	(const MockNamedValueComparatorsAndCopiersRepository& repository);
    virtual void removeAllComparatorsAndCopiers();

protected:
    MockSupport* clone(const SimpleString& mockName);
    virtual MockCheckedActualCall *createActualFunctionCall();
    virtual void failTest(MockFailure& failure);
    void countCheck();

private:
    int callOrder_;
    int expectedCallOrder_;
    bool strictOrdering_;
    MockFailureReporter *activeReporter_;
    MockFailureReporter *standardReporter_;
    MockFailureReporter defaultReporter_;
    MockExpectedCallsList expectations_;
    MockExpectedCallsList unExpectations_;
    bool ignoreOtherCalls_;
    bool enabled_;
    MockCheckedActualCall *lastActualFunctionCall_;
    MockExpectedCallComposite compositeCalls_;
    MockNamedValueComparatorsAndCopiersRepository comparatorsAndCopiersRepository_;
    MockNamedValueList data_;
    const SimpleString mockName_;

    bool tracing_;

    void checkExpectationsOfLastCall();
    bool wasLastCallFulfilled();
    void failTestWithUnexpectedCalls();
    void failTestWithOutOfOrderCalls();

    MockNamedValue* retrieveDataFromStore(const SimpleString& name);

    MockSupport* getMockSupport(MockNamedValueListNode* node);

    bool hasntExpectationWithName	(const SimpleString& functionName);
    bool hasntUnexpectationWithName	(const SimpleString& functionName);
    bool hasCallsOutOfOrder();

    SimpleString appendScopeToName	(const SimpleString& functionName);

};

#endif

