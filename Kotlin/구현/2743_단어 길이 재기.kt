/* BOJ - 2743 단어 길이 재기 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val writer = BufferedWriter(OutputStreamWriter(System.out))
    val wordLength = reader.readLine().length

    writer.write("$wordLength")
    writer.close()
}