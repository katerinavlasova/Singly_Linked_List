#define BOOST_TEST_MODULE mytests
#include <boost/test/included/unit_test.hpp>
#include "SinglyLinkedList.h"

using namespace List;

struct Fixture
{
public:
	Fixture() : list(0) {}
	LinkedList<int> list;
};

BOOST_FIXTURE_TEST_CASE(TestCase_FrontOneElement, Fixture)
{
	BOOST_CHECK_EQUAL(list.front(), 0);
}

BOOST_FIXTURE_TEST_CASE(TestCase_FrontForTwoElements, Fixture)
{
	list.pushBack(1);
	BOOST_CHECK_EQUAL(list.front(), 0);
}

BOOST_FIXTURE_TEST_CASE(TestCase_CheckSizeForOneElement, Fixture)
{
	BOOST_CHECK_EQUAL(list.getSize(), 1);
}

BOOST_FIXTURE_TEST_CASE(TestCase_CheckSizeForTwoElements, Fixture)
{
	list.pushFront(3);
	BOOST_CHECK_EQUAL(list.getSize(), 2);
}

BOOST_FIXTURE_TEST_CASE(TestCase_CheckSizeForNoElements, Fixture)
{
	list.popBack();
	list.popBack();
	BOOST_CHECK_EQUAL(list.getSize(), 0);
}

BOOST_FIXTURE_TEST_CASE(TestCase_IsEmptyForNotEmptyList, Fixture)
{
	BOOST_CHECK_EQUAL(list.isEmpty(), false);
}

BOOST_FIXTURE_TEST_CASE(TestCase_IsEmptyForEmptyList, Fixture)
{
	list.popBack();
	BOOST_CHECK_EQUAL(list.isEmpty(), true);
}

BOOST_FIXTURE_TEST_CASE(TestCasePopBackFromNoElementList, Fixture)
{
	BOOST_CHECK_EQUAL(list.popBack(), NULL);
}

BOOST_FIXTURE_TEST_CASE(TestCasePopFrontFromNoElementList, Fixture)
{
	BOOST_CHECK_EQUAL(list.popBack(), NULL);
}

BOOST_FIXTURE_TEST_CASE(TestCasePopBackFromOneElementList, Fixture)
{
	list.pushBack(1);
	BOOST_CHECK_EQUAL(list.popBack(), 1);
}

BOOST_FIXTURE_TEST_CASE(TestCasePopFrontFromOneElementList, Fixture)
{
	list.pushBack(1);
	BOOST_CHECK_EQUAL(list.popBack(), 1);
}

BOOST_FIXTURE_TEST_CASE(TestCasePushBackToNoElementList, Fixture)
{
	BOOST_CHECK_EQUAL(list.pushBack(1), 1);
}

BOOST_FIXTURE_TEST_CASE(TestCasePushFrontToNoElementList, Fixture)
{
	BOOST_CHECK_EQUAL(list.pushFront(1), 1);
}

BOOST_FIXTURE_TEST_CASE(TestCasePushBackToOneElementList, Fixture)
{
	BOOST_CHECK_EQUAL(list.pushBack(2), 2);
}

BOOST_FIXTURE_TEST_CASE(TestCasePushFrontToOneElementList, Fixture)
{
	BOOST_CHECK_EQUAL(list.pushFront(2), 2);
}