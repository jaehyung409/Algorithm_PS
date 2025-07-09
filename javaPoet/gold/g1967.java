package javaPoet.gold;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Vector;
import static java.util.Collections.sort;

public class g1967 {
    public static int diameter = 0;

    public static class Node {
        Vector<Node> children;
        int weightFromParent;
        int firstMax = 0; // max path length from this node to leaf
        int secondMax = 0; // second max path length from this node to leaf

        public Node(int weightFromParent) {
            this.children = new Vector<>();
            this.weightFromParent = weightFromParent;
        }
        public void addChild(Node child) {
            children.add(child);
        }
    }

    public static void calculateDiameter(Node node) {
        if (node == null) {
            return;
        }
        Vector<Integer> childWeights = new Vector<>();
        for (Node child : node.children) {
            calculateDiameter(child);
            int pathLength = child.weightFromParent + child.firstMax;
            childWeights.add(pathLength);
        }
        sort(childWeights);
        if (childWeights.size() > 0) {
            node.firstMax = childWeights.lastElement();
        }
        if (childWeights.size() > 1) {
            node.secondMax = childWeights.get(childWeights.size() - 2);
        }
        if (node.firstMax + node.secondMax > diameter) {
            diameter = node.firstMax + node.secondMax;
        }
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        Node[] nodes = new Node[10001];
        nodes[1] = new Node(0); // root node
        for (int i = 0; i < n - 1; i++) {
            int parent, child, weight;
            String[] input = br.readLine().split(" ");
            parent = Integer.parseInt(input[0]);
            child = Integer.parseInt(input[1]);
            weight = Integer.parseInt(input[2]);
            if (nodes[parent] == null) {
                nodes[parent] = new Node(0);
            }
            if (nodes[child] == null) {
                nodes[child] = new Node(weight);
            } else {
                nodes[child].weightFromParent = weight;
            }
            nodes[parent].addChild(nodes[child]);
        }
        calculateDiameter(nodes[1]);
        System.out.println(diameter);
    }
}
