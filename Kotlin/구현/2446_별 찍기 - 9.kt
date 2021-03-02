/* BOJ - 2446_별 찍기 - 9 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun makeStar(size: Int): MutableList<String> {
    val stars = mutableListOf<String>()
    for (downCount in size downTo 1) {
        stars.add(" ".repeat(size - downCount) + "*".repeat(2 * downCount - 1))
    }
    for (index in stars.lastIndex - 1 downTo 0) {
        stars.add(stars[index])
    }

    return stars
}

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))

    val n = bufferedReader.readLine().toInt()
    makeStar(n).forEach { element -> bufferedWriter.write("$element\n") }
    bufferedWriter.close()
}