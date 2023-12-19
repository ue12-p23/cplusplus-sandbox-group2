#include <iostream>

class Node
{
public:
  int value;
  Node *next{nullptr};
  Node() = default;
  Node(int value) : value(value) {}
};

class List
{
  Node *head{nullptr};

public:
  void append(int value)
  {
    Node *new_node = new Node();
    new_node->value = value;
    if (head == nullptr)
    {
      head = new_node;
    }
    else
    {
      Node *current = head;
      while (current->next != nullptr)
      {
        current = current->next;
      }
      current->next = new_node;
    }
  }

  void print()
  {
    Node *current = head;
    while (current != nullptr)
    {
      std::cout << current->value << std::endl;
      current = current->next;
    }
  }

  void insert(int value, int index)
  {
    Node *new_node = new Node();
    new_node->value = value;
    if (index == 0)
    {
      new_node->next = head;
      head = new_node;
    }
    else
    {
      Node *current = head;
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
    Node *current = head;
    while (current != nullptr)
    {
      size++;
      current = current->next;
    }
    return size;
  }

  ~List()
  {
    Node *current = head;
    while (current != nullptr)
    {
      Node *next = current->next;
      delete current;
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