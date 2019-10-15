
using Proyecto26;
using System.Collections;
using System.Collections.Generic;
using UnityEditor;
using UnityEngine;
using UnityEngine.UI;
using Newtonsoft.Json;
using Newtonsoft.Json.Linq;
using System.Linq;

public class LeaderBoardManager : MonoBehaviour
{
    public Text Names;
    public Text Scores;
    public GameObject content;
    
    // Start is called before the first frame update
    void Start()
    {
        retrieveFromDatabase();
        
    }

    // Gets data from database using REST
    public void retrieveFromDatabase()
    {

        RestClient.Get("https://spacejump-d32d8.firebaseio.com/.json?orderBy=\"userScore\"").Then(response =>
        {
            parseData(response.Text);
           
        });
    }

    // Parses data and places them into text columns
    public void parseData(string response)
    {
        Names.text = "";
        Scores.text = "";
        // Parse the JSON String
        Dictionary<string, User> users = JsonConvert.DeserializeObject<Dictionary<string, User>>(response);

        // Convert parsed String to a list of users
        List<User> user_list = users.Select(x => x.Value).ToList();
        List<User> SortedList = user_list.OrderBy(o => o.userScore).ToList();

        // Insert objects into text boxes on UI
        for (int i = 0; i < SortedList.Count; i++)
        {
            Names.text = " " + SortedList[i].userName + "\n" +Names.text;
            Scores.text = " " + SortedList[i].userScore + "\n" + Scores.text;
        }

        // Resize content box to fit the text
        RectTransform rt_content = content.GetComponent<RectTransform>();
        RectTransform rt_text = Names.GetComponent<RectTransform>();
        rt_content.sizeDelta = new Vector2(rt_content.sizeDelta.x, rt_text.sizeDelta.y);

    } 

   

}
