#pragma once

#include <memory>

namespace lab10
{
	template<typename T>
	class Node
	{
	public:
		Node(std::unique_ptr<T> data);
		Node(std::unique_ptr<T> data, std::shared_ptr<Node<T>> prev);
		std::unique_ptr<T> Data;
		std::shared_ptr<Node<T>> Next;
		std::weak_ptr<Node<T>> Previous;
	};

	template<typename T>
	Node<T>::Node(std::unique_ptr<T> data)
		: Data(std::move(data))
		, Next(nullptr)
		// Previous(nullptr) 컴파일 오류 발생(없어도 문제 없이 작동)
	{
	}

	template<typename T>
	Node<T>::Node(std::unique_ptr<T> data, std::shared_ptr<Node<T>> prev)
		: Data(std::move(data))
		, Previous(prev)
		, Next(prev->Next) 
	{
	}
}