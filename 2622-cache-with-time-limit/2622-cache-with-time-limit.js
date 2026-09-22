var TimeLimitedCache = function() {
    this.cache = new Map();
};

TimeLimitedCache.prototype.set = function(key, value, duration) {
    const currentTime = Date.now();

    if (this.cache.has(key)) {
        const old = this.cache.get(key);

        if (old.expiry > currentTime) {
            clearTimeout(old.timer);
            
            const timer = setTimeout(() => {
                this.cache.delete(key);
            }, duration);

            this.cache.set(key, {
                value: value,
                expiry: currentTime + duration,
                timer: timer
            });

            return true;
        }
    }

    const timer = setTimeout(() => {
        this.cache.delete(key);
    }, duration);

    this.cache.set(key, {
        value: value,
        expiry: currentTime + duration,
        timer: timer
    });

    return false;
};

TimeLimitedCache.prototype.get = function(key) {
    if (!this.cache.has(key)) {
        return -1;
    }

    const item = this.cache.get(key);

    if (item.expiry <= Date.now()) {
        this.cache.delete(key);
        return -1;
    }

    return item.value;
};

TimeLimitedCache.prototype.count = function() {
    const currentTime = Date.now();
    let count = 0;

    for (const [key, item] of this.cache) {
        if (item.expiry > currentTime) {
            count++;
        } else {
            this.cache.delete(key);
        }
    }

    return count;
};