package com.example.jnitest

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import com.example.jnitest.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {
    companion object {
        init {
            System.loadLibrary("jnitest")
        }
    }

    private external fun printStingFromNdk(): String

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        binding.button.setOnClickListener {
            binding.text.text = printStingFromNdk()
        }
    }
}