/* BOJ - 3046 R2 */

package boj

import java.io.BufferedReader
import java.io.BufferedWriter
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.util.*

fun main() {
    val reader = BufferedReader(InputStreamReader(System.`in`))
    val writer = BufferedWriter(OutputStreamWriter(System.out))
    val r2 = StringTokenizer(reader.readLine()).let { token ->
        val r1 = token.nextToken().toInt()
        val s = token.nextToken().toInt()
        -r1 + s * 2
    }
    writer.write("$r2")
    writer.close()
}