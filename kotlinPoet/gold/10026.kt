package kotlinPoet.gold

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    val painting = Array(n) {
        br.readLine().toCharArray()
    }
    val visited = Array(n) { BooleanArray(n) { false } }

    val normal = divideSector(n, painting, visited)
    visited.forEach { row -> row.fill(false) }
    val rgBlind = divideSector(n, painting, visited)
    println("$normal $rgBlind")
}

fun divideSector(size: Int, painting: Array<CharArray>, visited: Array<BooleanArray>): Int {
    return (0 until size).flatMap { y ->
        (0 until size).mapNotNull { x ->
            val result = if (!visited[y][x]) {
                painting.dfs(y, x, visited, painting[y][x])
                1
            } else null
            if (painting[y][x] != 'B') {
                painting[y][x] = 'S'
            } // side effect : R,G -> Same Color
            result
        }
    }.size
}

fun Array<CharArray>.dfs(y: Int, x: Int, visited: Array<BooleanArray>, color: Char) {
    if (y !in indices || x !in this[0].indices || visited[y][x] || this[y][x] != color) return
    visited[y][x] = true
    dfs(y + 1, x, visited, color)
    dfs(y - 1, x, visited, color)
    dfs(y, x + 1, visited, color)
    dfs(y, x - 1, visited, color)
}