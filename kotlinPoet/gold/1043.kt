package kotlinPoet.gold

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.StringTokenizer

fun main() {
    val br = BufferedReader(InputStreamReader(System.`in`))
    val (n, m) = StringTokenizer(br.readLine(), " ").run {
        IntArray(2) { this.nextToken().toInt() }
    }
    var count = 0
    val party: MutableList<String> = mutableListOf()
    val set: HashSet<Int> = br.readLine().split(" ")
        .drop(1)
        .map { it.toInt() }
        .toHashSet()
    repeat(m) {
        party.add(
            br.readLine().split(" ")
            .drop(1)
            .joinToString(" ")
        )
    }
    repeat(m-1) {
        party.filter { list ->
            list.split(" ").any { set.contains(it.toInt()) }
        }.forEach { list ->
            set.addAll(list.split(" ").map { it.toInt() })
        }
    }
    party.forEach {
        count += it.split(" ").takeUnless { list ->
            list.any { set.contains(it.toInt()) }
        }?.let { 1 } ?: 0
    }
    println(count)
}