/* BOJ - 14681 사분면 고르기 */

package boj

import java.io.BufferedReader
import java.io.InputStreamReader

const val ZERO = 0

fun main() {
    val bufferedReader = BufferedReader(InputStreamReader(System.`in`))
    val x = bufferedReader.readLine().toInt()
    val y = bufferedReader.readLine().toInt()

    val quadrant = when (ZERO < x) {
        true -> if (ZERO < y) 1 else 4
        false -> if (ZERO < y) 2 else 3
    }

    println(quadrant)
    bufferedReader.close()
}