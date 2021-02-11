/* BOJ - 11654 아스키 코드 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val asciiValue = bufferedReader.read()

    println(asciiValue)
    bufferedReader.close()
}