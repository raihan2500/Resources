#!/usr/bin/env python3
from graphviz import Graph  # Digraph থেকে Graph এ পরিবর্তন

def main():
    #n = int(input())
    n, m = (map(int, input().split()))
    edges = []
    for _ in range(m):
        u, v = map(int, input().split())
        edges.append((u, v))

    dot = Graph()  # Digraph() এর বদলে Graph()
    
    for u, v in edges:
        dot.edge(str(u), str(v))

    dot.attr(rankdir='TB')  # Top to Bottom layout

    dot.render('tree_output', view=True, format='png')

if __name__ == "__main__":
    main()


# from graphviz import Graph

# def main():
#     n = int(input())
#     colors_input = list(map(int, input().split()))
#     edges = []
#     for _ in range(n - 1):
#         u, v = map(int, input().split())
#         edges.append((u, v))

#     # 0 -> white, 1 -> black
#     color_map = {0: 'white', 1: 'black'}

#     dot = Graph()

#     # node 1 থেকে n পর্যন্ত color assign করা হবে
#     for i in range(1, n + 1):
#         color = color_map.get(colors_input[i - 1], 'white')  # default white
#         fontcolor = 'white' if color == 'black' else 'black'  # black background হলে লেখার রং হোক white
#         dot.node(str(i), style='filled', fillcolor=color, fontcolor=fontcolor)

#     for u, v in edges:
#         dot.edge(str(u), str(v))

#     dot.attr(rankdir='TB')
#     dot.render('colored_tree_output', view=True, format='png')

# if __name__ == "__main__":
#     main()
