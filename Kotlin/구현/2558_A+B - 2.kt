/* BOJ - 2558 A+B - 2 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`)).let {
        val a = it.readLine().toInt()
        val b = it.readLine().toInt()
        println(a + b)
    }
}