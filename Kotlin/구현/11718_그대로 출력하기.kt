/* BOJ - 11718 그대로 출력하기 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val bufferedWriter = BufferedWriter(OutputStreamWriter(System.out))

    do {
        val input = bufferedReader.readLine() ?: break
        bufferedWriter.write("$input\n")
    } while (true)

    bufferedReader.close()
    bufferedWriter.close()
}