/* BOJ - 2443 별 찍기 - 6 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun makeStar(size: Int) = mutableListOf<String>().apply {
    repeat (size) { line ->
        this.add(" ".repeat(line) + "*".repeat(2 * (size - line) - 1))
    }
}

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val writer = BufferedWriter(OutputStreamWriter(System.out))
    val n = reader.readLine().toInt()

    makeStar(n).forEach { writer.write("$it\n") }
    writer.close()
}