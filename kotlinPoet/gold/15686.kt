package kotlinPoet.gold

import java.io.BufferedReader
import java.io.InputStreamReader
import kotlin.math.abs

fun distance(y1: Int, x1: Int, y2: Int, x2: Int): Int {
    return abs(y1 - y2) + abs(x1 - x2)
}

fun Int.combinations(r: Int): List<List<Int>> {
    fun combine(start: Int, depth: Int, path: List<Int>): List<List<Int>> {
        if (depth == r) return listOf(path)
        val result = mutableListOf<List<Int>>()
        for (i in start until this) {
            result.addAll(combine(i + 1, depth + 1, path + i))
        }
        return result
    }
    return combine(0, 0, emptyList())
}

fun getChickenDistance(houses: List<Pair<Int, Int>>,
                                       chicken: List<Pair<Int, Int>>,
                                       combinations: List<List<Int>>) : Int {
    var ans = Int.MAX_VALUE
    combinations.forEach { combine ->
        var totalDistance = 0
        houses.forEach { (hy, hx) ->
            var minDistance = Int.MAX_VALUE
            combine.forEach { index ->
                val (cy, cx) = chicken[index]
                minDistance = minOf(minDistance, distance(hy, hx, cy, cx))
            }
            totalDistance += minDistance
        }
        ans = minOf(ans, totalDistance)
    }
    return ans
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = br.readLine().split(" ").map { it.toInt() }
    // input array n X n
    val city = (0 until n).flatMap { i ->
        br.readLine()!!
            .split(" ")
            .mapIndexedNotNull { j, v ->
                val value = v.toInt()
                if (value == 1 || value == 2) Triple(i, j, value) else null
            }
    }
    val (houses, chicken) = city.partition { it.third == 1 }
    println(
        getChickenDistance(
            houses.map { Pair(it.first, it.second) },
            chicken.map { Pair(it.first, it.second) },
            chicken.size.combinations(m)
        )
    )
}