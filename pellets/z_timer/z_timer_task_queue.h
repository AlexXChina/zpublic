#pragma once
#include <queue>

/*
 * ACE�Ķ�ʱ�������ṩ��heap��wheel�����飩��hash��list���ֲ��Է�ʽ
 * libeventʹ�õ���minheap
 * libuvʹ�õ���rbtree
 * �����ܡ����������ӶȵȽǶȿ��Ǻ������ʹ�õ���stl��priority_queue
 * Ҳ��ˣ�ֻ�����������ɾ������
 * ���̰߳�ȫ���ⲿ��������֤
 */

class TimerTaskBase;

class TimerTaskQueue
{
public:
    TimerTaskQueue() {}
    ~TimerTaskQueue() {}

public:
    bool Insert(TimerTaskBase* pTask)
    {
        queue_.push(pTask);
        return true;
    }

    TimerTaskBase* Top()
    {
        return queue_.top();
    }

    TimerTaskBase* Pop()
    {
        TimerTaskBase* pTask = queue_.top();
        queue_.pop();
        return pTask;
    }

    unsigned int Size()
    {
        return (unsigned int)queue_.size();
    }

private:
    std::priority_queue<TimerTaskBase*, std::vector<TimerTaskBase*>, TimerTaskCmp> queue_;
};
