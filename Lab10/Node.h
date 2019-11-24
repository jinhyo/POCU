#pragma once

#include <memory>

namespace lab10
{
	template<typename T>
	class Node
	{
		// friend class DoublyLinkedList;

	public:
		Node(std::unique_ptr<T> data);
		Node(std::unique_ptr<T> data, std::shared_ptr<Node<T>> prev);
		std::unique_ptr<T> Data;
		std::shared_ptr<Node<T>> Next;
		std::weak_ptr<Node<T>> Previous;
	};

	template<typename T>
	Node<T>::Node(std::unique_ptr<T> data)
		: Data(data)
		, Next(nullptr)
		, Previous(nullptr)
	{
	}

	template<typename T>
	Node<T>::Node(std::unique_ptr<T> data, std::shared_ptr<Node<T>> prev)
		: Data(data)
		, Next(prev->Next)
		, Previous(prev)
	{
		prev->Next(this);
	}
}