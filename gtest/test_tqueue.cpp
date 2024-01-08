#include "pch.h"
#include "../Queue/Queue.h"

TEST(TQueue, CAN_CREATE_POSITIVE_QUEUE)
{
    ASSERT_NO_THROW(TQueue<int> q);
}

TEST(TQueue, NEW_QUEUE_IS_EMPTY)
{
    TQueue<int> q;

    ASSERT_TRUE(q.empty());
}

TEST(TQueue, CAN_PUSH)
{
    TQueue<int> q;
    ASSERT_NO_THROW(q.push(1));
}

TEST(TQueue, CAN_POP)
{
    TQueue<int> q;
    int a;
    q.push(1);
    ASSERT_NO_THROW(a = q.pop());
    EXPECT_EQ(1, a);
}

TEST(TQueue, POP_ON_EMPTY_QUEUE_THROWS)
{
    TQueue<int> q;
    ASSERT_ANY_THROW(q.pop());
}

TEST(TQueue, CAN_FRONT_OR_BACK)
{
    TQueue<int> q;
    q.push(1); q.push(1);

    ASSERT_NO_THROW(q.front());
    ASSERT_NO_THROW(q.back());
    EXPECT_EQ(q.front(), q.back());
}

TEST(TQueue, FRONT_OR_BACK_ON_EMPTY_QUEUE_THROWS)
{
    TQueue<int> q;

    ASSERT_ANY_THROW(q.front());
    ASSERT_ANY_THROW(q.back());
}

TEST(TQueue, QUEUE_IS_NOT_FULL)
{
    TQueue<int> q;
    q.push(1);

    ASSERT_FALSE(q.full());
}

TEST(TQueue, QUEUE_IS_EMPTY)
{
    TQueue<int> q;

    ASSERT_TRUE(q.empty());
}

TEST(TQueue, QUEUE_IS_NOT_EMPTY)
{
    TQueue<int> q;
    q.push(1);

    ASSERT_FALSE(q.empty());
}

TEST(TQueue, COMPARE_TWO_EQUAL_QUEUES)
{
    TQueue<int> q1, q2;
    q1.push(1); q1.push(1);
    q2.push(1); q2.push(1);

    ASSERT_TRUE(q1 == q2);
}

TEST(TQueue, COMPARE_TWO_DIFFERENT_QUEUES)
{
    TQueue<int> q1, q2;
    q1.push(0); q1.push(0);
    q2.push(1); q2.push(1);

    ASSERT_TRUE(q1 != q2);
}