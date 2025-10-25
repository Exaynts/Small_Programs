using System;
using System.Collections.Generic;
using System.Xml.Linq;

namespace SearchInAGraph
{
    public class Graph
    {
        // Данные графа
        private int vertices; // Число вершин
        private List<List<int>> adjacencyList; // Список смежности

        // Создаём граф
        private Graph(int v, List<List<int>> adjList)
        {
            vertices = v;
            adjacencyList = adjList;
        }

        // Вводим данные
        public static Graph Input()
        {
            // Ввод числа вершин
            Console.Write("Natural number of vertices: ");
            int vert = Input_nums.InputNatural();
            // Ориентированость графа
            Console.Write("Make the graph directed? " +
                "\nIf so, write '+'; otherwise, leave it out): ");
            string dir_text = Console.ReadLine();
            // Создание списка смежности
            List<List<int>> adjList;
            if (dir_text == "+")
            {
                adjList = CreateAdjList_directed(vert);
            }
            else { 
                adjList = CreateAdjList(vert);
            }
            // Создаем и возвращаем граф
            Graph graph = new Graph(vert, adjList);
            return graph;
        }

        // Ввод списка смежности ориентированного графа
        static public List<List<int>> CreateAdjList_directed(int vertices)
        {
            List<List<int>> list = new List<List<int>>();
            Console.WriteLine("Adjacency list ");
            for (int i = 0; i < vertices; i++)
            {
                list.Add(new List<int>());
                for (int j = 0; j < vertices; j++)
                {
                    Console.Write($"Elem[{i}][{j}]: "); // Пример: Elem[0][0]: 1
                    int n = int.Parse(Console.ReadLine());
                    list[i].Add(n);
                }
            }
            return list;
        }

        // Ввод списка смежности неориентированного графа
        static public List<List<int>> CreateAdjList(int vertices)
        {
            // Инициализируем список
            List<List<int>> list = new List<List<int>>();
            for (int i = 0; i < vertices; i++)
            {
                list.Add(new List<int>(new int[vertices])); // Заполнение нулями по умолчанию
            }

            Console.WriteLine("Adjacency list ");
            for (int i = 0; i < vertices; i++)
            { // Добавление элементов выше главной диагонали
                list.Add(new List<int>());
                for (int j = i; j < vertices; j++)
                {
                    Console.Write($"Elem[{i}][{j}]: ");
                    int n = int.Parse(Console.ReadLine());
                    list[i][j] = n; // Добавляем Elem[i][j]
                    list[j][i] = n; // Добавляем Elem[j][i]
                }
            }
            return list;
        }
        // Вывод списка смежности
        public void PrintAdjacencyList()
        {
            for (int i = 0; i < vertices; i++)
            {
                for (int j = 0; j < vertices; j++)
                {
                    Console.Write(adjacencyList[i][j] + " ");
                }
                Console.WriteLine();
            }
        }
        // Выбор начальной и конечной вершины
        public (int start, int end) ChooseStartAndEndVertices() {
            Console.Write("Initial vertex: ");
            int start = Input_nums.InputNatural();
            Console.Write("Final vertex: ");
            int end = Input_nums.InputNatural();
            return (start, end);
        }
        // Поиск в ширину
        public int BreadthFirstSearch(int start, int end) { // Возвратит расстояние между вершинами, если они не связаны, вернет -1
            if (start == end) return 0;
            List<int> usedVertices = new List<int> { start }; // Список использованных вершин
            int used_index = 0; // Индекс прохода по списку использованных вершин

            int tier_num = 1; // Ярус
            List<int> tier = new List<int> {start}; // Список вершин на одном ярусе
            while (tier.Count > 0)
            { // Проходим по всем ярусам, пока не найдется искомая вершина
                List<int> newtier = new List<int>(); // Создаем новый ярус
                foreach (int item in tier)
                { // Проходим по каждой вершине яруса
                    for (int i = 0; i < vertices; i++)
                    {
                        if (this.adjacencyList[item][i] != 0 && !(usedVertices.Contains(i))) // Если имеется новое ребро к новой вершине
                        {
                            if (i == end) { return tier_num; } // Если новая вершина оказалась конечной
                            usedVertices.Add(i);
                            newtier.Add(i);
                        }
                    }
                }
                if (newtier.Count == 0) { return -1; } // Если ни одна вершина из яруса не связана ни с какой новой, заканчиваем поиск
                // Вывод элементов яруса на консоль
            Console.Write($"tier[{tier_num}]: ");
            foreach (int t in newtier) { Console.Write($"{t} "); }
                Console.WriteLine();
                // Пересивывание элементов яруса
                tier_num += 1;
                tier = newtier;
            }
            return tier_num;
        }

        // Поиск в глубину (со стеком)
        public bool DepthFirstSearch(int start, int end)
        {
            if (start == end) return true;

            bool[] visited = new bool[vertices];
            Stack<int> stack = new Stack<int>();

            stack.Push(start);
            visited[start] = true;

            while (stack.Count > 0)
            {
                int current = stack.Pop();

                if (current == end) return true;

                // Добавляем соседей в стек (в обратном порядке для сохранения порядка обхода)
                for (int neighbor = vertices - 1; neighbor >= 0; neighbor--)
                {
                    if (adjacencyList[current][neighbor] != 0 && !visited[neighbor])
                    {
                        visited[neighbor] = true;
                        stack.Push(neighbor);
                        // Выводим стек
                        Console.Write($"stack: ");
                        foreach (int item in stack) { Console.Write($"{item} "); }
                        Console.WriteLine();
                    }
                }
            }

            return false;
        }
    }
}
