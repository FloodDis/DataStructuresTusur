#include "IOAVLTree.h"

void AVLTreeMenu()
{
	/// <summary>
	/// Действия, которые можно совершить с АВЛ-деревом
	/// </summary>
	enum Actions
	{
		/// <summary>
		/// Добавить элемент
		/// </summary>
		AddElement = 1,

		/// <summary>
		/// Удалить элемент
		/// </summary>
		DeleteElement = 2,

		/// <summary>
		/// Найти элемент
		/// </summary>
		FindElement = 3,

		/// <summary>
		/// Тест производительности
		/// </summary>
		Test = 4,

		/// <summary>
		/// Выйти в главное меню
		/// </summary>
		Exit = 5
	};

	setlocale(LC_ALL, "ru");
	AVLTree* treeUnit = new AVLTree;
	Show(treeUnit->GetRoot());
	while (true)
	{
		cout << "Выберите действие:\n"
			<< "1) Добавить элемент\n"
			<< "2) Удалить элемент\n"
			<< "3) Найти элемент\n"
			<< "4) Тест производительности\n"
			<< "5) Выйти\n";
		int option = EnterNumber("");
		switch (option)
		{
			case AddElement:
			{
				int	keyOfNewNode =
					EnterNumber("Введите ключ нового элемента: ");
				try
				{
					treeUnit->Insert(keyOfNewNode);
				}
				catch (char const* error)
				{
					cout << error << '\n';
				}
				Show(treeUnit->GetRoot());
				break;
			}

			case DeleteElement:
			{
				int keyToDelete =
					EnterNumber("Введите ключ удаляемого элемента: ");
				try
				{
					treeUnit->Delete(keyToDelete);
					cout << "Элемент был удален из дерева!\n";
				}
				catch (char const* error)
				{
					cout << error << '\n';
				}
				Show(treeUnit->GetRoot());
				break;
			}

			case FindElement:
			{
				AVLTreeNode* answer = nullptr;
				int searchingKey =
					EnterNumber("Введите ключ искомого элемента: ");
				answer = treeUnit->Find(searchingKey);
				if (answer == nullptr)
				{
					cout << "Элемент не найден!\n";
				}
				else
				{
					cout << "Элемент с ключом " << answer->Key << " есть в дереве\n";
				}
				Show(treeUnit->GetRoot());
				break;
			}

			case Test:
			{
				cout << "Performance tests are executing. Please wait...\n";
				ofstream file{ "AVLTreePerformanceTest.txt" };
				file << GetTreePerformanceMeasurementAVL(treeUnit);
				file.close();
				cout << "Performance tests are finished. Result are saved in file.\n";
				break;
			}

			case Exit:
			{
				return;
			}

			default:
			{
				cout << "Попробуйте снова!\n";
				Show(treeUnit->GetRoot());
				break;
			}
		}
	}
}

void Show(AVLTreeNode* rootNode)
{
	cout << "Ваше АВЛ-дерево:\n";
	Print(rootNode, 0);
}

void Print(AVLTreeNode* rootNode, int tabCount)
{
	if (rootNode != nullptr)
	{
		Print(rootNode->Right, tabCount + 1);
		for (int i = 0; i < tabCount; i++)
		{
			cout << "\t";
		}
		cout << "(" << rootNode->Key << "; " << rootNode->Data << ")";
		if (rootNode->Left != nullptr && rootNode->Right != nullptr)
		{
			cout << "|\n";
		}
		if (rootNode->Left == nullptr && rootNode->Right != nullptr)
		{
			cout << "/\n";
		}
		if (rootNode->Left != nullptr && rootNode->Right == nullptr)
		{
			cout << "\\\n";
		}
		if (rootNode->Left == nullptr && rootNode->Right == nullptr)
		{
			cout << "\n";
		}
		Print(rootNode->Left, tabCount + 1);
	}
}