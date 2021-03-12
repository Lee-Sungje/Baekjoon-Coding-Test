/* BOJ - 10808 알파벳 개수 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

const val ALPHABET_LENGTH = 26
const val START_ALPHABET = 'a'

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val writer = BufferedWriter(OutputStreamWriter(System.out))
    val word = reader.readLine()
    val alphabetCount = Array(ALPHABET_LENGTH) { 0 }

    word.forEach { alphabet -> alphabetCount[alphabet - START_ALPHABET] += 1 }
    alphabetCount.forEach { count -> writer.write("$count ") }
    writer.close()
}