package kotlinPoet.gold

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer


fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var st = StringTokenizer(br.readLine(), " ")
    val (row, col) = IntArray(2) { st.nextToken().toInt() }

    val papers = Array(row) {
        StringTokenizer(br.readLine(), " ").run {
            IntArray(col) {
                nextToken().toInt()
            }
        }
    }

    val max = (0 until row).flatMap { y ->
        (0 until col).map { x ->
            papers.maxTetromino(y, x)
        }
    }.max()

    println(max)
}

val tetrominoShapes = listOf(
    listOf(Pair(1, 0), Pair(2, 0), Pair(3, 0)),
    listOf(Pair(1, 0), Pair(2, 0), Pair(2, 1)),
    listOf(Pair(1, 0), Pair(2, 0), Pair(1, 1)),
    listOf(Pair(1, 0), Pair(2, 0), Pair(0, 1)),
    listOf(Pair(1, 0), Pair(1, 1), Pair(2, 1)),
    listOf(Pair(1, 0), Pair(1, 1), Pair(1, 2)),
    listOf(Pair(1, 0), Pair(1, 1), Pair(0, 1)),
    listOf(Pair(1, 0), Pair(0, 1), Pair(0, 2)),
    listOf(Pair(1, 0), Pair(0, 1), Pair(-1, 1)),
    listOf(Pair(0, 1), Pair(1, 1), Pair(2, 1)),
    listOf(Pair(0, 1), Pair(1, 1), Pair(1, 2)),
    listOf(Pair(0, 1), Pair(1, 1), Pair(0, 2)),
    listOf(Pair(0, 1), Pair(1, 1), Pair(-1, 1)),
    listOf(Pair(0, 1), Pair(0, 2), Pair(1, 2)),
    listOf(Pair(0, 1), Pair(0, 2), Pair(0, 3)),
    listOf(Pair(0, 1), Pair(0, 2), Pair(-1, 2)),
    listOf(Pair(0, 1), Pair(-1, 1), Pair(0, 2)),
    listOf(Pair(0, 1), Pair(-1, 1), Pair(-1, 2)),
    listOf(Pair(0, 1), Pair(-1, 1), Pair(-2, 1)),
)

fun Array<IntArray>.maxTetromino(y: Int, x: Int): Int{
    var maxScore = 0
    for (shape in tetrominoShapes) {
        var sum = this[y][x]
        for ((dy, dx) in shape) {
            if (y + dy in this.indices && x + dx in this[0].indices) {
                sum += this[y + dy][x + dx]
            } else {
                sum = 0
                break
            }
        }
        maxScore = maxOf(maxScore, sum)
    }
    return maxScore
}