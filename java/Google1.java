import java.util.Arrays;
import java.util.HashMap;

public class Google1
{
    public static int[] solution(int[] data, int n)
    {
        if (n < 1) return new int[] {};

        HashMap<Integer, Integer> amountMap = new HashMap<>();

        for (int id : data) {
            int amount = amountMap.containsKey(id) ? amountMap.get(id) + 1 : 1;
            amountMap.put(id, amount);
        }

        // raw version without any fancy streams
//        List<Integer> dataList = new ArrayList<>();
//        for (int id : data) {
//            if (amountMap.get(id) < n + 1) {
//                dataList.add(id);
//            }
//        }
//
//        return dataList.stream()
//                .mapToInt(Integer::intValue)
//                .toArray();

        // Version with array streams that worked locally for the public test cases, but not on google servers
        return Arrays.stream(data).filter(id -> amountMap.get(id) < n + 1).toArray();
    }
}