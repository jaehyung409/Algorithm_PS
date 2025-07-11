package kotlinPoet.gold

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    val solutions = br.readLine().split(" ").map { it.toLong() }.toMutableList()
    solutions.sort()
    var closestSum: Long = Long.MAX_VALUE
    var closestCombination: Triple<Long, Long, Long> = Triple(0, 0, 0)
    solutions.forEachIndexed { index, solution ->
        var left = index + 1
        var right = solutions.size - 1
        while (left < right) {
            val sum: Long = solution + solutions[left] + solutions[right]
            if (Math.abs(sum) < Math.abs(closestSum)) {
                closestSum = sum
                closestCombination = Triple(solution, solutions[left], solutions[right])
            }
            if (sum == 0.toLong()) {
                println("${solution} ${solutions[left]} ${solutions[right]}")
                return
            } else if (sum < 0) {
                left++
            } else {
                right--
            }
        }
    }
    println("${closestCombination.first} ${closestCombination.second} ${closestCombination.third}")
}