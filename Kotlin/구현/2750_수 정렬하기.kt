/* BOJ - 2750 수 정렬하기 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))
    val length = bufferedReader.readLine().toInt()

    val numbers = mutableListOf<Int>()
    repeat(length) {
        numbers.add(bufferedReader.readLine().toInt())
    }
    numbers.sort()
    repeat(length) {
        bufferedWriter.write("${numbers[it]}\n")
    }

    bufferedReader.close()
    bufferedWriter.close()
}