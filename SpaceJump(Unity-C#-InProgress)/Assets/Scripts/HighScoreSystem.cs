using Proyecto26;
using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class HighScoreSystem : MonoBehaviour
{
    public InputField nameEntered;
    public static string playerName;
    public static float playerScore;
    
    public void OnSubmitClick()
    {
        playerName = nameEntered.text;
        playerScore = PlayerPrefs.GetFloat("PlayerScore");
        PostToDatabase();
    }

    private void PostToDatabase()
    {
        User user = new User();
        
        RestClient.Put<User>("https://spacejump-d32d8.firebaseio.com/" + playerName + ".json", user);
    }
    
}
