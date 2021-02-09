/* BOJ - 10430 나머지 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader
import java.lang.StringBuilder
import java.util.*

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val stringTokenizer = StringTokenizer(bufferedReader.readLine())
    val a = stringTokenizer.nextToken().toInt()
    val b = stringTokenizer.nextToken().toInt()
    val c = stringTokenizer.nextToken().toInt()

    val stringBuilder = StringBuilder()
    stringBuilder.append("${(a + b) % c}\n")
    stringBuilder.append("${((a % c) + (b % c)) % c}\n")
    stringBuilder.append("${(a * b) % c}\n")
    stringBuilder.append("${((a % c) * (b % c)) % c}\n")
    print(stringBuilder)
    bufferedReader.close()
}