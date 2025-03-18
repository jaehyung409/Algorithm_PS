package kotlinPoet.gold

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun chainingMax(current: Int, nums: List<Int>): Int {
    return nums.max() + current
}

fun chainingMin(current: Int, nums: List<Int>): Int {
    return nums.min() + current
}

fun IntArray.downMax(before: IntArray): IntArray {
    val ret = IntArray(3)
    ret[0] = chainingMax(this[0], before.take(2))
    ret[1] = chainingMax(this[1], before.take(3))
    ret[2] = chainingMax(this[2], before.takeLast(2))
    return ret
}

fun IntArray.downMin(before: IntArray): IntArray {
    val ret = IntArray(3)
    ret[0] = chainingMin(this[0], before.take(2))
    ret[1] = chainingMin(this[1], before.take(3))
    ret[2] = chainingMin(this[2], before.takeLast(2))
    return ret
}

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val n = br.readLine().toInt()
    var tempMax = StringTokenizer(br.readLine(), " ").run {
        IntArray(3) { this.nextToken().toInt() }
    }
    var tempMin = tempMax.copyOf()
    repeat(n - 1) {
        val arr = StringTokenizer(br.readLine(), " ").run {
            IntArray(3) { this.nextToken().toInt() }
        }
        tempMax = arr.downMax(tempMax)
        tempMin = arr.downMin(tempMin)
    }
    println("${tempMax.max()} ${tempMin.min()}")
}