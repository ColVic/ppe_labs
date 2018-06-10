//
//  Preferences.swift
//  EggTimer
//
//  Created by Colta Victor on 4/29/18.
//  Copyright © 2018 Colta Victor. All rights reserved.
//

import Foundation

struct Preferences {
    
    var selectedTime: TimeInterval {
        get {
            let savedTime = UserDefaults.standard.double(forKey: "selectedTime")
            if savedTime > 0 {
                return savedTime
            }
            return 360
        }
        set {
            UserDefaults.standard.set(newValue, forKey: "selectedTime")
        }
    }
    
}
