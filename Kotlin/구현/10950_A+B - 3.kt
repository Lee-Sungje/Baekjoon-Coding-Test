/* BOJ - 10950 A+B - 3 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    var testcase = bufferedReader.readLine().toInt()

    val stringBuilder = StringBuilder()
    while (0 < testcase--) {
        val stringTokenizer = StringTokenizer(bufferedReader.readLine())
        val a = stringTokenizer.nextToken().toInt()
        val b = stringTokenizer.nextToken().toInt()

        stringBuilder.append("${a + b}\n")
    }
    print(stringBuilder)
    bufferedReader.close()
}