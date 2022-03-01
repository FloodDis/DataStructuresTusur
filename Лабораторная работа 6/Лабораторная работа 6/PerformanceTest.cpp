#include "PerformanceTest.h"

string GetTreePerformanceMeasurementAVL(AVLTree* tree)
{
	stringstream output;

	output << "Count\tInsert\tFind\tDelete\n";

	Vector<int> keys;
	for (int i = 0; i <= 100; ++i)
	{
		int uniqueKey = rand();
		while (tree->Find(uniqueKey) != nullptr)
		{
			uniqueKey += 1;
		}

		keys.PushBack(uniqueKey);
		tree->Insert(uniqueKey);

		output << i << '\t';
		output << GetAverageExecutionTimeOfAVL("Insert()", tree, keys)
			<< '\t';
		output << GetAverageExecutionTimeOfAVL("Find()", tree, keys)
			<< '\t';
		output << GetAverageExecutionTimeOfAVL("Delete()", tree, keys)
			<< '\t';

		output << '\n';
	}
	return output.str();
}

string GetTreePerformanceMeasurementRB(RBTree* tree)
{
	stringstream output;

	output << "Count\tInsert\tFind\tDelete\n";

	Vector<int> keys;
	for (int i = 0; i <= 100; ++i)
	{
		int uniqueKey = rand();
		while (tree->Find(uniqueKey) != nullptr)
		{
			uniqueKey += 1;
		}

		keys.PushBack(uniqueKey);
		tree->Insert(uniqueKey);

		output << i << '\t';
		output << GetAverageExecutionTimeOfRB("Insert()", tree, keys)
			<< '\t';
		output << GetAverageExecutionTimeOfRB("Find()", tree, keys)
			<< '\t';
		output << GetAverageExecutionTimeOfRB("Delete()", tree, keys)
			<< '\t';

		output << '\n';
	}
	return output.str();
}

long long GetAverageExecutionTimeOfAVL(string operationName,
	AVLTree* tree, Vector<int>& keys)
{
	Stopwatch stopwatch;

	long long averageTime = 0;

	for (int i = 0; i < 10'000; ++i)
	{
		if (operationName == "Insert()")
		{
			int uniqueKey = rand();
			while (tree->Find(uniqueKey) != nullptr)
			{
				uniqueKey += 1;
			}

			keys.PushBack(uniqueKey);

			stopwatch.Start();
			tree->Insert(uniqueKey);
			stopwatch.Stop();

			tree->Delete(keys.GetElement(keys.GetSize() - 1));
			keys.PopBack();
		}
		else if (operationName == "Delete()")
		{
			int existedKey = keys.GetElement(rand() % keys.GetSize());
			keys.DeleteElement(keys.FindLinary(existedKey));

			stopwatch.Start();
			tree->Delete(existedKey);
			stopwatch.Stop();

			int uniqueKey = rand();
			while (tree->Find(uniqueKey) != nullptr)
			{
				uniqueKey += 1;
			}
			keys.PushBack(uniqueKey);
			tree->Insert(uniqueKey);
		}
		else if (operationName == "Find()")
		{
			stopwatch.Start();
			tree->Find(keys.GetElement(rand() % keys.GetSize()));
			stopwatch.Stop();
		}
		else
		{
			throw "Error: operationName parament is incorrect.";
		}
		averageTime += stopwatch.GetDuration();
		stopwatch.Reset();
	}

	return averageTime / 10'000;
}

long long GetAverageExecutionTimeOfRB(string operationName,
	RBTree* tree, Vector<int>& keys)
{
	Stopwatch stopwatch;

	long long averageTime = 0;

	for (int i = 0; i < 10'000; ++i)
	{
		if (operationName == "Insert()")
		{
			int uniqueKey = rand();
			while (tree->Find(uniqueKey) != nullptr)
			{
				uniqueKey += 1;
			}

			keys.PushBack(uniqueKey);

			stopwatch.Start();
			tree->Insert(uniqueKey);
			stopwatch.Stop();

			tree->Delete(keys.GetElement(keys.GetSize() - 1));
			keys.PopBack();
		}
		else if (operationName == "Delete()")
		{
			int existedKey = keys.GetElement(rand() % keys.GetSize());
			keys.DeleteElement(keys.FindLinary(existedKey));

			stopwatch.Start();
			tree->Delete(existedKey);
			stopwatch.Stop();

			int uniqueKey = rand();
			while (tree->Find(uniqueKey) != nullptr)
			{
				uniqueKey += 1;
			}
			keys.PushBack(uniqueKey);
			tree->Insert(uniqueKey);
		}
		else if (operationName == "Find()")
		{
			stopwatch.Start();
			tree->Find(keys.GetElement(rand() % keys.GetSize()));
			stopwatch.Stop();
		}
		else
		{
			throw "Error: operationName parament is incorrect.";
		}
		averageTime += stopwatch.GetDuration();
		stopwatch.Reset();
	}

	return averageTime / 10'000;
}