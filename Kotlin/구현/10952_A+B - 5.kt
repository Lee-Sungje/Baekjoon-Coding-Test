/* BOJ - 10952_A+B - 5 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val stringBuilder = StringBuilder()

    do {
        val stringTokenizer = StringTokenizer(bufferedReader.readLine())
        val a = stringTokenizer.nextToken().toInt()
        val b = stringTokenizer.nextToken().toInt()

        if (a == 0 && b == 0) {
            break
        } else {
            stringBuilder.append("${a + b}\n")
        }
    } while (true)

    print(stringBuilder)
    bufferedReader.close()
}