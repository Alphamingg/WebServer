#include<thread>
#include<mutex>
#include<atomic>
#include<condition_variable>
#include<functional>
#include<vector>
#include<queue>

template<typename T>
//任务队列
class SafeQueue
{
private:
    std::queue<T> m_queue;//任务队列
    std::mutex m_mutex;
public:
    SafeQueue(){}
    SafeQueue(SafeQueue&& other){}
    ~SafeQueue(){}

    bool empty()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.empty();
        
    }

    int size()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        return m_queue.size();
    }

    void enqueue(T& t)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        m_queue.emplace(t);
    }

    bool dequeue(T& t)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        if(m_queue.empty())
        {
            return false;
        }
        t = std::move(m_queue.front());
        m_queue.pop();
        return true;
    }

};
int main()
{

    
    return 0;
}