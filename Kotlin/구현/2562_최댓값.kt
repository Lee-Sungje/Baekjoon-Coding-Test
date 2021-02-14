/* BOJ - 2562 최댓값 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))

    var maxIndex = 0
    var maxNumber = 0
    for (index in 1..9) {
        val number = bufferedReader.readLine().toInt()
        if (maxNumber < number) {
            maxNumber = number
            maxIndex = index
        }
    }
    bufferedWriter.write("$maxNumber\n$maxIndex")

    bufferedReader.close()
    bufferedWriter.close()
}