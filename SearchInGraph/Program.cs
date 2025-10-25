using System;
using System.Runtime.InteropServices;

namespace SearchInAGraph {
    class Program
    {
        static void Main()
        {
            // Ввод данных (число вершин и список смежности)
            Graph graph = Graph.Input();
            // Вывод списка смежности
            graph.PrintAdjacencyList();
            // Выбор начальной и конечной вершин графа
            (int start, int end) = graph.ChooseStartAndEndVertices();
            // Выбор метода поиска
            Console.Write("Choose the method for search in graph \nIf breadth-first, write 'b' \nIf depth-first, write 'd': ");
            string search_method = Console.ReadLine();
            int distance = 0;

            if (search_method == "b") // Поиск в ширину
            {
                distance = graph.BreadthFirstSearch(start, end);
                // Вывод результата
                if (distance == -1)
                    Console.Write("The vertices in the graph are nit connected");
                else
                    Console.Write($"The distance between vertices equals to: {distance}");
            }

            if (search_method == "d") // Поиск в глубину
            {
                bool isconnected = graph.DepthFirstSearch(start, end);
                // Вывод результата
                if (isconnected == true)
                    Console.Write("The vertices in the graph are connected");
                else
                    Console.Write("The vertices in the graph aren't connected");
            }

        }
    }
}
