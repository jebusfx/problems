/*input
2
4
5
1 4 5 3 2
4
4
2 2 4 3
*/
import java.io.*;
import java.util.*;

public class IceCream{
	private class TheIceCream implements Comparable<TheIceCream>{
		private int id;
		private int cost;

		public TheIceCream(int id, int cost){
			this.id = id;
			this.cost = cost;
		}
		public int getId(){
			return id;
		}
		public void setId(int id){
			this.id = id;
		}
		public int getCost(){
			return cost;
		}
		public void setCost(){
			this.cost = cost;
		}

		public int compareTo(TheIceCream ic2){
			return cost - ic2.getCost();
		}
	}
	private void twoPointer(ArrayList<TheIceCream> list, int sum){
		int i = 0, j = list.size() - 1;
		while(i < j){
			if(list.get(i).getCost() + list.get(j).getCost() == sum){
				int id_i = list.get(i).getId();
				int id_j = list.get(j).getId();
				System.out.printf("%d %d\n", Math.min(id_i, id_j), Math.max(id_i, id_j));
				return;
			}
			else if(list.get(i).getCost() + list.get(j).getCost() > sum) j--;
			else i++;
		}
	}

	public static void main(String[] args){
		IceCream ic = new IceCream();
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		while((t--) > 0){
			int sum = in.nextInt();
			int n = in.nextInt();
			ArrayList<TheIceCream> arr = new ArrayList<>();
			for(int i = 1; i <= n; i++){
				arr.add(ic.new TheIceCream(i,in.nextInt()));
			}
			Collections.sort(arr);
			/*arr.sort(new Comparator<TheIceCream>(){
				@Override
				public int compare(TheIceCream ic1, TheIceCream ic2){
					return ic1.getCost() - ic2.getCost();
				}
			});*/
			ic.twoPointer(arr, sum);
		}
	}
}
