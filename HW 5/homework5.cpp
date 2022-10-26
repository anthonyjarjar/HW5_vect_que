#include <iostream>
#include <vector>
using namespace std;
// For this homework, you are going to implement an extendable vector based queue that
// uses "jump" trick to save space.
// Finish function
//              front() that prints the first element in the queue
//              deque() that dequeues the queue
//           enque(val) that enqueues val to the queue
//              print_vect() that prints out vect_que.
// Demonstrate that your code works in main.
// Refer to class PPT if you forgot all the different cases.
template <typename T>
class vect_queue
{
    std::vector<T> vect_que;
    size_t size_;
    int que_front_;
    int que_back_;

public:
    vect_queue(T val)
    {
        vect_que.push_back(val);
        size_ = 1;
        que_front_ = 0;
    }

    /*
    T front() const;
    void deque();
    void enque(T val);
    void print_vect() const;
    int map(int n);
    T back() const;
    */

    T front() const
    {
        return vect_que[que_front_];
    }

    T back() const
    {
        return vect_que[que_back_];
    }

    int map(int n)
    {
        int i = 0;

        if (vect_que.size() != 0)
        {
            if (que_front_ + i < vect_que.size())
            {
                i = n + que_front_;
            }

            else
            {
                i = n + que_front_ - vect_que.size();
            }
        }
        return i;
    }

    void deque()
    {
        if (size_ > 1)
        {
            vect_que[que_front_] = NULL;
            size_--;

            if (que_front_ == vect_que.size() - 1)
            {
                que_front_ = 0;
            }

            else
            {
                que_front_++;
            }
        }

        else if (size_ == 1)
        {
            vect_que[que_front_] = NULL;
            size_--;

            que_back_ = 0;

            que_front_ = 0;
        }

        else
        {
            std::cout << "Empty container" << std::endl;
        }
    }

    void enque(T val)
    {

        if (size_ < vect_que.size())
        {

            if (size_ == 0)
            {
                size_++;
                vect_que[que_front_] = val;
            }

            else
            {
                size_++;
                if (que_back_ != vect_que.size() - 1)
                {
                    vect_que[que_back_ + 1] = val;
                    que_back_++;
                }

                else
                {
                    vect_que[0] = val;
                    que_back_ = 0;
                }
            }
        }

        else if (size_ == vect_que.size())
        {

            std::vector<T> temp;
            if (vect_que.size() > 0)
            {
                temp.resize(vect_que.size() * 2);
                for (int i = 0; i < size_; i++)
                {
                    temp[que_front_ + i] = vect_que[map(i)];
                }

                temp[que_front_ + size_] = val;
                que_back_ = que_front_ + size_;

                vect_que = temp;
                size_++;
            }

            else
            {
                temp.resize(1);
                temp.push_back(val);
                que_back_ = 1;
                vect_que = temp;
                size_++;
            }
        }

        else
        {
            std::cout << "Vect Capacity Full"
                      << "\n\n";
        }
    }

    void print_vect() const
    {
        for (int i = 0; i < vect_que.size(); i++)
        {
            std::cout << vect_que[i] << " ";
        }
        std::cout << std::endl;
        std::cout << "The front index of queue = " << que_front_ << std::endl;
        std::cout << "The back index of queue = " << que_back_ << std::endl;
    }
};

int main()
{
    // Demonstrate your code works by adding/removing values in a vect_que class
    // object. Print out your result.
    // You should include front index of queue, back index of queue, and the entire
    // vector (not queue) for each case.

    // case 1: add to an empty que

    vect_queue<int> vector(1);
    vector.print_vect();

    // case 2: add to a non-empty queue without jump

    std::cout << std::endl;
    vector.enque(2);
    vector.print_vect();

    // case 3: add to a non-empty queue with a jump

    std::cout << std::endl;
    vector.deque();
    vector.enque(100);
    vector.print_vect();

    // case 4: remove from a queue with number of elements > 1
    //         and que.front not at vect.back

    std::cout << std::endl;
    vector.deque();
    vector.deque();
    vector.enque(10);
    vector.enque(20);

    vector.deque();
    vector.print_vect();

    // case 5: remove from a queue with number of elements > 1
    //         and que.front at vect.back

    std::cout << std::endl;
    vector.enque(30);
    vector.deque();
    vector.print_vect();

    // case 6: remove from a queue with 1 element in it and que.front
    //         not at vect[0]

    std::cout << std::endl;
    vector.enque(40);
    vector.deque();
    vector.deque();
    vector.print_vect();

    cout
        << "\nprogram ends here.\n";
    return 0;
}