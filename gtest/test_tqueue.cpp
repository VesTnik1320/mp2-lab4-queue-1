#include "pch.h"
#include "../Queue/Queue.h"

TEST(TQueue, CAN_CREATE_POSITIVE_QUEUE)
{
    ASSERT_NO_THROW(TQueue<int> q(3));
}

TEST(TQueue, CANT_CREATE_NEGATIVE_QUEUE)
{
    ASSERT_ANY_THROW(TQueue<int> q(-5));
}

TEST(TQueue, CAN_GET_SIZE)
{
    TQueue<int> q(5);

    EXPECT_EQ(0, q.getSize());
}

TEST(TQueue, NEW_QUEUE_IS_EMPTY)
{
    TQueue<int> q(5);

    ASSERT_TRUE(q.empty());
}

TEST(TQueue, CAN_PUSH)
{
    TQueue<int> q(5);
    ASSERT_NO_THROW(q.push(1));
}

TEST(TQueue, CAN_POP)
{
    TQueue<int> q(5);
    int a;
    q.push(1);
    ASSERT_NO_THROW(a = q.pop());
    EXPECT_EQ(1, a);
}

TEST(TQueue, POP_ON_EMPTY_QUEUE_THROWS)
{
    TQueue<int> q(5);
    ASSERT_ANY_THROW(q.pop());
}

TEST(TQueue, PUSH_ON_FULL_QUEUE_THROWS)
{
    TQueue<int> q(2);
    q.push(1);
    q.push(1);
    ASSERT_ANY_THROW(q.push(1));
}

TEST(TQueue, CAN_FRONT_OR_BACK)
{
    TQueue<int> q(2);
    q.push(1); q.push(1);

    ASSERT_NO_THROW(q.front());
    ASSERT_NO_THROW(q.back());
    EXPECT_EQ(q.front(), q.back());
}

TEST(TQueue, FRONT_OR_BACK_ON_EMPTY_QUEUE_THROWS)
{
    TQueue<int> q(3);

    ASSERT_ANY_THROW(q.front());
    ASSERT_ANY_THROW(q.back());
}

TEST(TQueue, QUEUE_IS_FULL)
{
    TQueue<int> q(3);
    q.push(1); q.push(1); q.push(1);

    ASSERT_TRUE(q.full());
}

TEST(TQueue, QUEUE_IS_NOT_FULL)
{
    TQueue<int> q(3);
    q.push(1);

    ASSERT_FALSE(q.full());
}

TEST(TQueue, QUEUE_IS_EMPTY)
{
    TQueue<int> q(3);

    ASSERT_TRUE(q.empty());
}

TEST(TQueue, QUEUE_IS_NOT_EMPTY)
{
    TQueue<int> q(3);
    q.push(1);

    ASSERT_FALSE(q.empty());
}

TEST(TQueue, COMPARE_TWO_EQUAL_QUEUES)
{
    TQueue<int> q1(3), q2(3);
    q1.push(1); q1.push(1);
    q2.push(1); q2.push(1);

    ASSERT_TRUE(q1 == q2);
}

TEST(TQueue, COMPARE_TWO_DIFFERENT_QUEUES)
{
    TQueue<int> q1(3), q2(3);
    q1.push(0); q1.push(0);
    q2.push(1); q2.push(1);

    ASSERT_TRUE(q1 != q2);
}