#include "pch.h"
#include "../Queue/Queue.h"

TEST(TQueue, Can_create_positive_queue)
{
    ASSERT_NO_THROW(TQueue<int> q(2));
}
TEST(TQueue, Can_create_big_positive_queue)
{
    ASSERT_NO_THROW(TQueue<int> q(99999));
}

TEST(TQueue, Can_create_negative_queue)
{
    ASSERT_ANY_THROW(TQueue<int> q(-2));
}

TEST(TQueue, Can_get_size)
{
    TQueue<int> q(3);

    EXPECT_EQ(0, q.getSize());
}

TEST(TQueue, Check_empty_of_new_queue)
{
    TQueue<int> q(5);

    ASSERT_TRUE(q.empty());
}

TEST(TQueue, Check_can_push)
{
    TQueue<int> q(5);
    ASSERT_NO_THROW(q.push(1));
}

TEST(TQueue, Check_can_pop)
{
    TQueue<int> q(5);
    int a;
    q.push(2);
    ASSERT_NO_THROW(a = q.pop());
    EXPECT_EQ(2, a);
}

TEST(TQueue, Check_can_pop_empte_queue)
{
    TQueue<int> q(3);
    ASSERT_ANY_THROW(q.pop());
}

TEST(TQueue, Check_can_push_in_full_queue)
{
    TQueue<int> q(3);
    q.push(8);
    q.push(1);
    q.push(2);
    ASSERT_ANY_THROW(q.push(2));
}

TEST(TQueue, Check_can_front_or_back)
{
    TQueue<int> q(2);
    q.push(1); q.push(1);

    ASSERT_NO_THROW(q.front());
    ASSERT_NO_THROW(q.back());
    EXPECT_EQ(q.front(), q.back());
}

TEST(TQueue, Check_front_or_back_empty_queue)
{
    TQueue<int> q(3);

    ASSERT_ANY_THROW(q.front());
    ASSERT_ANY_THROW(q.back());
}

TEST(TQueue, Check_ful_queue)
{
    TQueue<int> q(3);
    q.push(8); q.push(1); q.push(2);

    ASSERT_TRUE(q.full());
}

TEST(TQueue, Check_full_queue_or_not)
{
    TQueue<int> q(3);
    q.push(1);

    ASSERT_FALSE(q.full());
}

TEST(TQueue, Check_empty_queue)
{
    TQueue<int> q(2);

    ASSERT_TRUE(q.empty());
}

TEST(TQueue, Check_queue_empty_or_not)
{
    TQueue<int> q(3);
    q.push(1);

    ASSERT_FALSE(q.empty());
}

TEST(TQueue, Check_compare_two_queues)
{
    TQueue<int> q1(3), q2(3);
    q1.push(1); q1.push(1);
    q2.push(1); q2.push(1);

    ASSERT_TRUE(q1 == q2);
}

TEST(TQueue, Check_compare_two_diffrent_queues)
{
    TQueue<int> q1(3), q2(3);
    q1.push(0); q1.push(0);
    q2.push(1); q2.push(1);

    ASSERT_TRUE(q1 != q2);
}