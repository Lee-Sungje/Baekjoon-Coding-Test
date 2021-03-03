/* BOJ - 2523 별 찍기 - 13 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun makeStar(size: Int) = mutableListOf<String>().apply {
    for (count in 1..size) {
        this.add("*".repeat(count))
    }
    for (index in this.lastIndex - 1 downTo 0) {
        this.add(this[index])
    }
}

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val writer = BufferedWriter(OutputStreamWriter(System.out))

    val n = reader.readLine().toInt()

    makeStar(n).forEach { writer.write("$it\n") }
    writer.close()
}