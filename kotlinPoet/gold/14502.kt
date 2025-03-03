package kotlinPoet.gold

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer
import kotlin.math.max

fun bfs(lab: Array<Array<Int>>, queue: ArrayDeque<List<Int>>): Int{
    val direction = arrayOf(
        intArrayOf(1, 0),
        intArrayOf(0, 1),
        intArrayOf(-1, 0),
        intArrayOf(0, -1)
    )
    var virusArea = 0
    val visited = ArrayDeque<List<Int>>()
    while (queue.isNotEmpty()) {
        val (y, x) = queue.removeFirst()
        for (dir in direction) {
            val (ny, nx) = intArrayOf(y + dir[0], x + dir[1])
            if ((lab.getOrNull(ny)
                    ?.getOrNull(nx) ?: continue) == 0
            ) {
                lab[ny][nx] = 1
                virusArea++
                visited.add(listOf(ny, nx))
                queue.add(listOf(ny, nx))
            }
        }
    }
    visited.forEach { (y, x) -> lab[y][x] = 0 }
    return virusArea
}

fun ArrayDeque<List<Int>>.copy(): ArrayDeque<List<Int>> {
    val copy = ArrayDeque<List<Int>>()
    copy.addAll(this.toList())
    return copy
}

fun main(){
    val br = BufferedReader(InputStreamReader(System.`in`))
    val st = StringTokenizer(br.readLine(), " ")
    val (n, m) = IntArray(2) { st.nextToken().toInt() }
    var emptySpaces = 0
    var maxSafeSpace = 0
    val queue = ArrayDeque<List<Int>>()
    val lab = Array(n) { y ->
        StringTokenizer(br.readLine(), " ").run {
            Array(m) { x ->
                nextToken().toInt().also {
                    if (it == 0) emptySpaces++
                    else if (it == 2) queue.add(listOf(y, x))
                }
            }
        }
    }
    for (i in 0 until n * m) {
        if (lab[i / m][i % m] != 0) continue
        lab[i / m][i % m] = 1
        for (j in i until n * m) {
            if (lab[j / m][j % m] != 0) continue
            lab[j / m][j % m] = 1
            for (k in j until n * m) {
                if (lab[k / m][k % m] != 0) continue
                lab[k / m][k % m] = 1
                maxSafeSpace = max(emptySpaces - bfs(lab, queue.copy()), maxSafeSpace)
                lab[k / m][k % m] = 0
            }
            lab[j / m][j % m] = 0
        }
        lab[i / m][i % m] = 0
    }
    println(maxSafeSpace - 3)
}