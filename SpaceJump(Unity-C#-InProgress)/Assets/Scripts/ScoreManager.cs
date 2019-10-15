using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class ScoreManager : MonoBehaviour
{
    public Text myScore;
    public float myScoreCount;
    public float pointsPerSecond;
    public bool isGameActive;

    // Start is called before the first frame update
    void Start()
    {
        
    }

    // Update is called once per frame
    void Update()
    {

        // If game is still running
        if(isGameActive)
        {
            myScoreCount += pointsPerSecond + Time.deltaTime;
        }
     
        
        // Truncate the float
        myScore.text = "Score: " + Mathf.Round(myScoreCount);
        PlayerPrefs.SetFloat("PlayerScore", Mathf.Round(myScoreCount));

    }
}
