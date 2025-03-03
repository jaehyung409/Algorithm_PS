package kotlinPoet.gold

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

/*
    Simple BFS (update only tomato = 0)
*/

fun main() {
    val direction = arrayOf(
        intArrayOf(1, 0, 0),
        intArrayOf(0, 1, 0),
        intArrayOf(-1, 0, 0),
        intArrayOf(0, -1, 0),
        intArrayOf(0, 0, 1),
        intArrayOf(0, 0, -1)
    ) // (x, y, height)
    val br = BufferedReader(InputStreamReader(System.`in`))
    val queue = ArrayDeque<List<Int>>()
    val st = StringTokenizer(br.readLine(), " ")
    val (m, n, h) = IntArray(3) { st.nextToken().toInt() }

    val tomatoes = Array(h) { z ->
        Array(n) { y ->
            StringTokenizer(br.readLine(), " ").run {
                Array(m) { x ->
                    nextToken().toInt().also { if (it == 1) queue.add(listOf(z, y, x)) }
                }
            }
        }
    } // input handling and queue init

    while (queue.isNotEmpty()) {
        val (z, y, x) = queue.removeFirst()
        for (dir in direction) {
            val newZ = dir[2] + z
            val newY = dir[1] + y
            val newX = dir[0] + x
            val predict = tomatoes.getOrNull(newZ)
                ?.getOrNull(newY)
                ?.getOrNull(newX) ?: -1 // check out of bound
            if (predict != 0) continue
            tomatoes[newZ][newY][newX] = tomatoes[z][y][x] + 1
            queue.add(listOf(newZ, newY, newX))
        }
    } // bfs

    val maxValue = tomatoes.flatten()        // 3 dim -> 2 dim
        .flatMap { it.toList() }             // 2 dim -> 1 dim
        .takeIf { it.all {num -> num != 0} } // if zero exist -> null
        ?.maxOrNull()
        ?: 0

    println(maxValue - 1)
}
