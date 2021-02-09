/* BOJ - 2753 윤년 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    println(bufferedReader.readLine().toInt().let { year ->
        if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) 1 else 0
    })
    bufferedReader.close()
}