using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameOverScore : MonoBehaviour
{
    public Text gameOverScore;

    void Start()
    {
        gameOverScore.text = "Score: " + PlayerPrefs.GetFloat("PlayerScore");
    }
   
}
