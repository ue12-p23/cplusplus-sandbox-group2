#include <iostream>
#include <memory>

class Node
{
public:
  int value;
  std::shared_ptr<Node> next{nullptr};
  Node() = default;
  Node(int value) : value(value) {}
};

class List
{
  std::shared_ptr<Node> head{nullptr};

public:
  void append(int value)
  {
    std::shared_ptr<Node> new_node = std::make_shared<Node>();
    new_node->value = value;
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
      std::cout << current->value << std::endl;
      current = current->next;
    }
  }

  void insert(int value, int index)
  {
    std::shared_ptr<Node> new_node = std::make_shared<Node>();
    new_node->value = value;
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
};

int main()
{
  List l;

  l.append(1);
  l.append(2);

  return EXIT_SUCCESS;
}