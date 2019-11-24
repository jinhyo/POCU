#pragma once

#include <cstring>
#include <memory>
#include "Node.h"

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;

	private:
		std::shared_ptr<Node<T>> mHead;
		std::shared_ptr<Node<T>> mTail;
		unsigned int mLength;
	};

	template<typename T>
	DoublyLinkedList<T>::DoublyLinkedList()
		: mHead(nullptr)
		, mTail(nullptr)
		, mLength(0)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		std::shared_ptr<Node<T>> newNode;

		// 리스트가 비어있는 경우
		if (mLength == 0)
		{
			newNode = std::make_shared<Node<T>>(std::move(data));
			mHead = newNode;
			mTail = newNode;
			++mLength;
		}

		else
		{
			newNode = std::make_shared<Node<T>>(std::move(data), mTail);
			mTail->Next = newNode;
			mTail = newNode;
			++mLength;
		}
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		std::shared_ptr<Node<T>> newNode = mHead;
		for (size_t i = 0; i < index && newNode != nullptr; i++)
		{
			newNode = newNode->Next;
		}

		// 리스트가 비어있는 경우
		if (mHead == nullptr)
		{
			newNode = std::make_shared<Node<T>>(std::move(data));
			mHead = newNode;
			mTail = newNode;
			++mLength;
		}

		// 리스트가 비어있지 않은 경우 가장 앞에 추가
		else if (mHead != nullptr && index == 0)
		{
			newNode = std::make_shared<Node<T>>(std::move(data));
			newNode->Next = mHead;
			mHead->Previous = newNode;
			mHead = newNode;
			++mLength;
		}

		// Tail에 추가
		else if (newNode == nullptr)
		{
			newNode = std::make_shared<Node<T>>(std::move(data), mTail);
			mTail->Next = newNode;
			mTail = newNode;
			++mLength;
		}

		// 노드들 사이에 추가
		else
		{
			std::shared_ptr<Node<T>> temp = newNode->Previous.lock();
			newNode = std::make_shared<Node<T>>(std::move(data), temp);
			newNode->Next = temp->Next;
			temp->Next = newNode; 
			++mLength;
		}
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>> del = mHead;
		while (del != nullptr && memcmp(static_cast<const void*>(del->Data.get()), static_cast<const void*>(&data), sizeof(data)) != 0)
		{
			del = del->Next;
		}
	
		// 리스트가 비어있는 경우 or 리스트에 해당 데이터가 없는 경우
		if (del == nullptr)
		{
			return false;
		}

		// 첫 번째 노드 삭제
		if (del == mHead)
		{
			mHead = del->Next;
			del = nullptr;
			--mLength;

			return true;
		}

		// 마지막 노드 삭제
		else if (del == mTail)
		{
			mTail = del->Previous.lock();
			mTail->Next = nullptr;
			// del->Previous->Next = nullptr; 컴파일 오류 발생
			del = nullptr;
			--mLength;

			return true;
		}

		// 중간 노드 삭제
		else
		{
			del->Previous.lock()->Next = del->Next;
			del->Next->Previous = del->Previous;
			del = nullptr;
			--mLength;

			return true;
		}
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> f = mHead;
		while (f != nullptr && memcmp(static_cast<const void*>(f->Data.get()), static_cast<const void*>(&data), sizeof(data)) != 0)
		{
			f = f->Next;
		}

		// 리스트가 비어있는 경우 or 리스트에 해당 데이터가 없는 경우
		if (f == nullptr)
		{
			return false;
		}

		else
		{
			return true;
		}
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		// 이건 어디에 쓰는지?
		/*auto x = std::make_unique<T>();
		std::shared_ptr<Node<T>> temp = std::make_shared<Node<T>>(std::move(x));*/

		std::shared_ptr<Node<T>> temp = mHead;
		for (size_t i = 0; i < index && temp != nullptr; i++)
		{
			temp = temp->Next;
		}

		return temp;
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mLength;
	}
}