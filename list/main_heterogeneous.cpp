#include <iostream>
#include <memory>

class Node
{
public:
  virtual ~Node() = default;
  std::shared_ptr<Node> next{nullptr};
  virtual void print(std::ostream &os) const = 0;
};

template <typename T>
class TNode : public Node
{
public:
  T value;
  TNode() = default;
  TNode(T value) : value(value) {}
  void print(std::ostream &os) const override
  {
    os << value;
  }

  T get() const
  {
    return value;
  }
};

/**
 * @brief A class representing a linked list.
 */
class List
{
  std::shared_ptr<Node> head{nullptr};

public:
  template <typename T>
  void append(T value)
  {
    std::shared_ptr<Node> new_node = std::make_shared<TNode<T>>(value);
    if (head == nullptr)
    {
      head = new_node;
    }
    else
    {
      std::shared_ptr<Node> current = head;
      while (current->next != nullptr)
      {
        current = current->next;
      }
      current->next = new_node;
    }
  }

  void print()
  {
    std::shared_ptr<Node> current = head;
    while (current != nullptr)
    {
      current->print(std::cout);
      std::cout << std::endl;
      current = current->next;
    }
  }

  template <typename T>
  void insert(T value, int index)
  {
    std::shared_ptr<Node> new_node = std::make_shared<TNode<T>>(value);
    if (index == 0)
    {
      new_node->next = head;
      head = new_node;
    }
    else
    {
      std::shared_ptr<Node> current = head;
      for (int i = 0; i < index - 1; i++)
      {
        current = current->next;
      }
      new_node->next = current->next;
      current->next = new_node;
    }
  }

  int size()
  {
    int size = 0;
    std::shared_ptr<Node> current = head;
    while (current != nullptr)
    {
      size++;
      current = current->next;
    }
    return size;
  }

  ~List()
  {
    std::shared_ptr<Node> current = head;
    while (current != nullptr)
    {
      std::shared_ptr<Node> next = current->next;
      current.reset();
      current = next;
    }
  }

  template <typename T>
  T get(int index)
  {
    std::shared_ptr<Node> current = head;
    for (int i = 0; i < index; i++)
    {
      current = current->next;
    }
    return std::dynamic_pointer_cast<TNode<T>>(current)->get();
  }
};

int main()
{
  // Create an empty list
  List myList;

  // Test append function
  myList.append(10);
  myList.append(0.01);
  myList.append(std::string("Hello"));
  myList.append(30);

  // Test print function
  myList.print();

  // Test insert function
  myList.insert(15, 3);
  myList.insert(25, 4);

  // Test size function
  std::cout << "Size of the list: " << myList.size() << std::endl; // Output: 5

  // Test get function
  std::cout << "Element at index 1: " << myList.get<double>(1) << std::endl;
  std::cout << "Element at index 2: " << myList.get<std::string>(2) << std::endl;
  std::cout << "Element at index 3: " << myList.get<int>(3) << std::endl;

  return 0;
}