import java.util.*; 
import java.io.*; 
public class WordsRate {public static void main(String[] args) throws Exception {

	BufferedReader infile = new BufferedReader(new FileReader("D:\\A_Tale_of_Two_Cities.txt"));
	String string;
	String file = null;
	while ((string = infile.readLine()) != null) {
		file += string;
	}
	file = file.toLowerCase();
	file = file.replaceAll("[^A-Za-z]", " ");
	file = file.replaceAll("\\s+", " ");
	String words[];
	words = file.split("\\s+");
	Map<String, Integer> hashMap = new HashMap<String, Integer>();
	for (int i = 0; i < words.length; i++) {
		String key = words[i];
		if (hashMap.get(key) != null) {
			int value = ((Integer) hashMap.get(key)).intValue();
			value++;
			hashMap.put(key, new Integer(value));
		} else {
			hashMap.put(key, new Integer(1));
		}
	}
	Map<String, Object> treeMap = new TreeMap<String, Object>(hashMap);
	Map<String, Object> treeMap1 = new TreeMap<String, Object>(hashMap);
	BufferedWriter bw = new BufferedWriter(new FileWriter("result1.txt")); 
Iterator iter = treeMap.entrySet().iterator(); 
	String ss1[]=new String[treeMap.size()];;
	int ss2[]=new int[treeMap.size()];
	int i=0;
	while (iter.hasNext()) { 
	Map.Entry entry = (Map.Entry) iter.next(); 
	int val = (Integer)entry.getValue(); 
	String key =(String) entry.getKey(); 
	ss1[i]=key;
	ss2[i]=val;
	i++;
	} 
	int sValue=0;
	String sKey="";
	for(int j=0;j<ss2.length;j++){
		for(int k=0;k<i;k++){
			if(ss2[j]>ss2[k]){
				sValue=ss2[j];
				sKey=ss1[j];
				ss2[j]=ss2[k];
				ss1[j]=ss1[k];
				ss2[k]=sValue;
				ss1[k]=sKey;
			}
		}
	}int[] strLengths = new int[ss2.length];
	for(int j=0 ;j<ss2.length; j++){
		  strLengths[j] = ss1[j].length();
		}
	for(int j=0;j<ss2.length;j++){
		if(strLengths[j]>=4)
		System.out.println(ss1[j]+"="+ss2[j]);
		bw.write(ss1[j]+"="+ss2[j]); 
		bw.newLine(); 
		bw.flush(); 
	}
}
}
