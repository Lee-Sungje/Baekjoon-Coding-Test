/* BOJ - 2441 별 찍기 - 4 */

package boj

import java.io.BufferedWriter
import java.io.OutputStreamWriter

fun main() {
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))
    val length = readLine()!!.toInt()

    for (numberOfStars in length downTo 1) {
        val spaces = " ".repeat(length-numberOfStars)
        val stars = "*".repeat(numberOfStars)
        bufferedWriter.write("$spaces$stars\n")
    }

    bufferedWriter.close()
}